package main

import (
	"errors"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"strings"
	"time"
)

func GetDir(dir, reg string) (string, error) {
	// 读取目录 dir 下的文件
	dirEntries, err := os.ReadDir(dir)

	if err != nil {
		return "", err
	}

	// 寻找符合 reg 正则表达式的子文件夹
	for _, dirEntry := range dirEntries {
		if !dirEntry.IsDir() {
			continue
		}
		match, err := regexp.MatchString(reg, dirEntry.Name())
		if err != nil {
			return "", err
		}
		if match {
			return dirEntry.Name(), nil
		}
	}
	return "", nil

}

func GetCompileDir(chapterId uint, exerciseId uint) (string, error) {

	chapterDir, err := GetDir(".", fmt.Sprintf("^%d-.*?", chapterId))
	if err != nil || chapterDir == "" {
		return "", errors.New("not found chapter directory ")
	}

	exerciseDir, err := GetDir(chapterDir, fmt.Sprintf("exercise-%d($|-.*?$)", exerciseId))
	if err != nil {
		return "", errors.New("not found exercise directory")
	}

	return fmt.Sprintf("./%s/%s", chapterDir, exerciseDir), nil
}

func GetCompileFiles(compileDir string) ([]string, error) {
	dirEntries, err := os.ReadDir(compileDir)
	if err != nil || len(dirEntries) == 0 {
		return nil, err
	}

	fileList := make([]string, len(dirEntries))
	i := 0
	for _, dirEntry := range dirEntries {
		if !dirEntry.IsDir() && strings.HasSuffix(dirEntry.Name(), ".cpp") {
			if i < len(dirEntries) {
				fileList[i] = filepath.Join(compileDir, dirEntry.Name())
				i = i + 1
			} else {
				fileList = append(fileList, filepath.Join(compileDir, dirEntry.Name()))
			}
		}
	}
	return fileList, nil
}

func Compile(compileDir string) error {

	compileFileList, err := GetCompileFiles(compileDir)
	if err != nil {
		return err
	}

	fmt.Println("编译文件...")
	for _, filename := range compileFileList {
		if filename != "" {
			fmt.Println(filename)
		}
	}

	gccArg := []string{"-std=c++11", "-o", fmt.Sprintf("%s/main", compileDir), "-I", compileDir}
	gccArg = append(gccArg, compileFileList...)

	// 编译代码
	cmd := exec.Command("g++", gccArg...)
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	err = cmd.Run()
	if err != nil {
		return errors.New("fail to compile the .cpp files in " + fmt.Sprintf("%s", compileDir))
	}

	fmt.Println("编译成功!\n")
	return nil
}

func Run(compileDir string) error {
	err := Compile(compileDir)
	if err != nil {
		return err
	}

	// 获取编译好的可执行二进制文件完整路径
	executableFile := fmt.Sprintf("%s/main", compileDir)

	fmt.Printf("执行%s\n", executableFile)

	fmt.Println("运行结果: ")

	// 执行编译好的可执行文件
	cmd := exec.Command(executableFile)
	// 将Command的输出定位到操作系统标准输出
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	// 一直阻塞到执行结束
	err = cmd.Run()
	if err != nil {
		return errors.New("cannot run the main after compiled *.cpp files! ")
	}

	err = os.Remove(executableFile)
	if err != nil {
		return errors.New("fail to remove " + executableFile + ", it maybe not exist!")
	}
	return nil
}

func main() {
	var chapterId uint
	var exerciseId uint
	var showTime bool

	flag.UintVar(&chapterId, "chapter", 0, "章节编号")
	flag.UintVar(&exerciseId, "exercise", 0, "练习单元编号")
	flag.BoolVar(&showTime, "showtime", false, "是否显示执行时间")

	flag.Parse()

	// 输入匿名参数即报错
	if flag.NArg() != 0 {
		fmt.Println("please use --help to instruct you how to do in a right way")
		return
	}

	start := time.Now().UnixMilli()

	compileDir, err := GetCompileDir(chapterId, exerciseId)
	if err != nil || compileDir == "" {
		fmt.Println("cannot find the compileDir which includes .cpp files")
		return
	}

	// 编译C++代码，执行可执行文件，删除可执行文件
	err = Run(compileDir)
	if err != nil {
		fmt.Println(err)
		return
	}

	end := time.Now().UnixMilli()

	if showTime {
		fmt.Printf("\n\ncost time: %d ms", end-start)
	}

	return
}
