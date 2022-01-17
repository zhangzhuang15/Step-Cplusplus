default:
	@g++ -shared -o libecho.dylib echo.cpp
	@gcc  main.c libecho.dylib -o main
	@./main 

clean:
	@rm -f libecho.dylib main


# 在 Arm64 MacOS 上，
#   g++ -c echo.cpp -o echo.o
#   gcc main.c echo.o -o main
#  会发生错误，提示找不到链接器
#  但是动态链接却可以成功

# 动态链接库后缀名因内核不同而有所区别

# windows中是 .dll
# MacOS下是 .dylib
# linux是 .so

# linux中命名一般是 libXXX.so的形式