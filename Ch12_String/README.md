# String Container
## 📝 목차
- [컨테이너 어댑터란](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-컨테이너-어댑터란)
- [Stack 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Stack-컨테이너)
- [Queue 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Queue-컨테이너)
- [Priority Queue 컨테이너](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch11_Container_Adapter#-Priority-Queue-컨테이너)

___
## ✔ String 컨테이너란
  - `string` 컨테이너는 문자만을 원소로 저장하고 문자열을 조작할 목적으로 만들어진 컨테이너
  - `C++` 표준 컨테이너의 요구사항을 모두 만족하지 않아서 유사 컨테이너에 속함
  - `string`은 시퀀스 컨테이너이며, 배열기반 컨테이너
  - 표준 `C++` 라이브러리는 문자와 관련된 두 컨테이너 (`string`, `wstring`)를 제공
    - `string`은 `char`형식 문자를 관리하기 위한 `basic_string<char>` 컨테이너의 `typedef`
    - `wstring`은 유니코드 문자(`wchar_t`)를 관리하기 위한 `basic_string<wchar_t>` 컨테이너의 `typedef`형식

___
## ✔ String의 주요 인터페이스와 특징
 - `String`의 주요 인터페이스로는 `at()`, `begin()`, `capacity()`, 
 `clear()`, `empty()`, `end()`, `erase()`, `max_size()`, `push_back()`,
`rbegin()`, `rend()`, `reserve()`, `resize()`, `size()`, `swap()`,`[]` 연산자,
비교 연산자 등이 존재하며 `vector`와 사용방법이 비슷함.


#### 📍 string 생성자


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
  