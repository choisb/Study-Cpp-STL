# Container Adapter
## 📝 목차
- [컨테이너 어댑터란](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-컨테이너-어댑터란)
- [Stack 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Stack-컨테이너)
- [Queue 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Queue-컨테이너)
- [Priority Queue 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Priority-Queue-컨테이너)

___
## ✔ 컨테이너 어댑터란
  - 컨테이너 어댑터는 다른 컨테이너의 인터페이스를 변경한 컨테이너
  - STL에는 다읨 세 가지의 컨테이너 어댑터 제공
  
    - `stack`: LIFO 방식의 컨테이너
    - `queue`: FIFO 방식의 컨테이너
    - `priority_queue`: 우선순위에 의해 관리되는 큐. 기본 (`less`(`<`)연산).

___
## ✔ Stack 컨테이너
#### 📍Stack 컨테이너란
  - Stack 컨테이너란 LIFO 방식의 컨테이너를 구현한 템플릿 클래스
  - stack 컨테이너의 기본 컨테이너는 `deque` 컨테이너
  - Stack의 Container 템플릿 인자로 받는 컨테이너는 인터페이스로 `empty()`, `size()`, `push_back()`, `pop_back()`, `back()`등 제공해야 함
    - STL이 제공하는 기본 컨테이너 중에서는 `vector`, `deque`, `list`가 이에 해당.
    - 추가로 이 인터페이스를 지원하는 사용자 컨테이너는 Queue가 될 수 있다.

    
  > 예시 소스 코드(`deque`사용) [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch11_Container_Adapter/ex01_stack.cpp)

___
## ✔ Queue 컨테이너
#### 📍Queue 컨테이너란
  - Queue 컨테이너란 FIFO 방식의 컨테이너를 구현한 템플릿 클래스
  - Queue 컨테이너의 기본 컨테이너는 `deque` 컨테이너
  - Queue의 Container 템플릿 인자로 받는 컨테이너는 인터페이스로 `empty()`, `size()`, `push_back()`, `pop_fornt()`, `front()`등의 인터페이스를 제공해야 함
    - STL이 제공하는 기본 컨테이너 중에서는 `deque`, `list`가 이에 해당. (`vector`는 Queue가 될 수 없다.)
    - 추가로 이 인터페이스를 지원하는 사용자 컨테이너는 Queue가 될 수 있다.
    
  > 예시 소스 코드 (`list`사용) [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch11_Container_Adapter/ex02_queue.cpp)

___
## ✔ Priority Queue 컨테이너
#### 📍Priority Queue 컨테이너란
  - Priority Queue 컨테이너란 우선순위 queue를 구현한 템플릿 클래스
  - Priority Queue 컨테이너에 설정된 기본 컨테이너는 `vector` 컨테이너
  - Priority Queue 는 내부적으로 STL의 힙 알고리즘인 `make_heap()`, `push_heap()`, `pop_heap()`을 사용하여 구현 되어있음
    - 때문에 Priority Queue의 Container 템플릿 인자로 받는 컨테이너는 임의 접근 반복자를 제공해야함
    - 추가적으로 `push_back()`, `pop_back()`, `front()`등의 인터페이스를 제공해야 함.
    - STL이 제공하는 기본 컨테이너 중에서는 `vector`, `deque` 컨테이너를 사용할 수 있다.
    
  > 예시 소스 코드 (`vector`, `deque`사용) [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch11_Container_Adapter/ex03_priority_queue.cpp)
  