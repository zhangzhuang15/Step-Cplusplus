#include <iostream>

#define println(item) std::cout << item << std::endl
#define print(item) std::cout << item

class Computer {
    private:
      int id;
    protected:
      int price;
    public:
      Computer(int _id, int _price): id(_id), price(_price) { println("I am just a computer"); }
  
      void echo() { 
          println("just a computer");
          print("price: "); print(price);
          println(" ");
          print("id: "); print(id);
          println("");
      }
};

class MacBook:  public Computer {
    private:
      int serial_id;
    
    public:
      MacBook(int _serial_id, int _price): 
        serial_id(_serial_id), price(_price){ println("I am MacBook"); }

    //   MacBook(int _serial_id, int _price): 
    //     Computer(0, _price),
    //         serial_id(_serial_id) {  println("I am MacBook"); }
      
      void echo() { 
          println("MacBook");
          print("price: "); print(price); 
          println("");
          print("serial_id: "); print(serial_id);
          println("");
          print("id: "); print(id);
          println("");
      }
};

int main() {

    MacBook book(112, 12999);
    book.echo();

}

// 请看 README.md

