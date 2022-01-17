# c: chapter缩写，表示章节编号
c=0

# e: exercise缩写，表示每个章节下的练习区编号
e=0

shell=/bin/bash
executable=./run-executable

default:
	@command -v g++ > /dev/null
	@if [[ $$? != 0 ]]; then\
	  echo "Sorry, please install g++ at first";\
	  echo "Suggestion: ";\
	  echo "";\
	  echo "MacOS: brew install g++ or install Xcode from App Store";\
	  echo "Linux: sudo apt-get install g++ or yum install g++";\
	  echo "Windows: get more information from the Internet";\
	  echo "";\
	fi
	@echo "\nrun 'make help'     so that  you can get more information\n"

help:
	@echo "Welcome to use Step Cplusplus\n"
	@echo "Usage:"
	@echo "       make <command> [arguments]\n\r"
	@echo "commands:"
	@echo ""
	@echo "       run        c=<chapterID> e=<exerciseID>"
	@echo "                  if you ignore c, c will be 0.So does e."
	@echo "                  example: "
	@echo "                           - make run c=1 e=3"
	@echo "                           compile and run the cpps in 1-variable/exercise-3"
	@echo ""
	@echo "                           - make run c=0 e=0"
	@echo "                           compile and run the cpps in 0-notes/"
	@echo ""
	@echo "                           - make run"
	@echo "                           just like running make run c=0 e=0"
	@echo "\n"
	@echo "       help        show this message"

run:
	@${executable} --chapter ${c} --exercise ${e}




