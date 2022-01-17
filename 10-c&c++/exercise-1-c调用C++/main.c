void echo(char* p);

int main() {
    char* p = "this is c";

    echo(p);

    return 0;
}

// 代码执行： 进入本目录， 执行 make
// 删除main，libcho.dylib: make clean