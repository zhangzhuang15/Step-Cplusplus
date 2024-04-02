#include <iostream>
#include <stack>
using namespace std;

// 将中序运算符字符串转换为 逆波兰表达式（RPN）
#define N_OPTR 9
const char pri[N_OPTR][N_OPTR] = {
              // 当前运算符
             /*      +      -     *     /      ^       !       (       )       \0      */
/* 栈 */      
/*   +  */          '>',   '>',  '<',  '<',   '<',    '<',    '<',    '>',     '>',

/*   -  */          '>',   '>',  '<',  '<',   '<',    '<',    '<',    '>',     '>',

/*   *  */          '>',   '>',  '>',  '>',   '<',    '<',    '<',    '>',     '>',

/*   /  */          '>',   '>',  '>',  '>',   '<',    '<',    '<',    '>',     '>',

/*   ^  */          '>',   '>',  '>',  '>',   '>',    '<',    '<',    '>',     '>',

/*   !  */          '>',   '>',  '>',  '>',   '>',    '>',    '<',    '>',     '>',

/*   (  */          '<',   '<',  '<',  '<',   '<',    '<',    '<',    '=',     ' ',

/*   )  */          ' ',   ' ',  ' ',  ' ',   ' ',    ' ',    ' ',    ' ',     ' ',

/*   \0 */          '<',   '<',  '<',  '<',   '<',    '<',    '<',    ' ',     '='
/* 顶*/
};
const char table[] = {'+', '-', '*', '/', '^', '!', '(', ')', '\0'};

bool is_digit(char const c) {
    return c >= '0' && c<='9';
}

void read_digit(char const* &S, stack<int>& opond) {
    int sum = 0;
    while(is_digit(*S)) {
        sum = 10*sum + (int)(*S-'0');
        S++;
    }
    opond.push(sum);
}

int get_pos(char const c) {
    int length = (sizeof(table)/sizeof(char));
    for(int i = 0; i < length; i++) {
        if (table[i] == c) return i;
    }
    return -1;
}

// 返回运算符 c1 c2优先级比较结果
char primer_result(char const c1, char const c2) {
   int pos1 = get_pos(c1);
   int pos2 = get_pos(c2);
   return pos1 == -1 || pos2 == -1 ? ' ': pri[pos1][pos2];
}

// S 中序运算符字符串
void generate_rpn(char const* S){
    stack<char> optr;// 存储运算符
    stack<int>  opond;// 存储操作数
    
    optr.push('\0');

    while(*S != '\0') { // optr 非空
      char c = *S;
      if (is_digit(c)) {
          read_digit(S, opond);
          cout<<opond.top()<<" ";
      } else {
          switch (primer_result(optr.top(), *S)) {
              case '<':
                optr.push(*S);
                S++;
                break;
              case '=':
                optr.pop();
                S++;
                break;
              case '>':
                cout<<optr.top()<<" ";
                optr.pop();
                break;
              default: exit(-1);
          }// switch
      }// else
    }//while
    while (!optr.empty()){
        cout<<optr.top()<<" ";
        optr.pop();
    }
}

int main() {
    char buffer[256];
    while(true){
        cout<<"输入中序表达式(输入0 结束)：";
        cin.getline(buffer, 256);
        if (buffer[0] == '0' && buffer[1] == '\0') break;
        generate_rpn(buffer);
        cout<<endl;
        memset(buffer, ' ', 256);
    }
}