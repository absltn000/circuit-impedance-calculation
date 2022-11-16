#pragma once

  const int size = 100;

  template<typename type>
  class TStack {
  private:
    type arr[size];
    int top;
  public:
    TStack() : top(-1) { }
    type get() const {
      return arr[top];
    }
    bool isEmpty() const {
      return top == -1;
    }
    bool isFull() const {
      return top == size - 1;
    }
    void pop() {
      if (top >= 0)
        top--;
    }
    void push(type item) {
      if (top < size - 1)
        arr[++top] = item;
    }
    ~TStack() {
    };
  };

