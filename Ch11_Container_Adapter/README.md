# Container Adapter
## 📝 목차
- [반복자란](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch10_Iterator#-반복자란)
- [정방향 반복자와 역방향 반복자](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch10_Iterator#-정방향-반복자와-역방향-반복자)
- [기타 반복자](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch10_Iterator#-기타-반복자)
- [반복자 특성과 보조 함수](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch10_Iterator#-반복자-특성과-보조-함수)

___
## ✔ 컨테이너 어댑터
- **컨테이너 어댑터란?**
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
  - Stack이 되기 위한 컨테이너는 `empty()`, `size()`, `push_back()`, `pop_back()`, `back()`등의 인터페이스를 제공해야 함
    - STL이 제공하는 기본 컨테이너 중에서는 `vector`, `deque`, `list`가 이에 해당.
    
  > 예시 소스 코드 [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch11_Container_Adapter/ex01_iterator_const_iterator.cpp)

#### 📍Stack 컨테이너 구성


- 모든 STL 컨테이너는 정방향 반복자 `::iterator`, `::const_iterator` 제공
  - `::iterator`: 정방향 반복자의 내장 형식. 반복자가 가리키는 원소 읽기 쓰기 가능
  - `::const_iterator`: 정방향 반복자의 내장형식. 분복자가 가리키는 원소 읽기만 가능 (쓰기 불가능)
  > 예시 소스 코드 [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch10_Iterator/ex01_iterator_const_iterator.cpp)

- 반복자가 가리키는 대상을 변경하지 않으려면 `const` 키워드를 사용하여 반복자를 상수화 한다. 
  > 예시 소스 코드 [(바로 가기)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch10_Iterator/ex02_const_const_iterator.cpp)

- 양방향 반복자
  - `list`, `set`, `multiset`, `multimap`은 양방향 반복자 지원
  - `*`,`->`,`++`,`--` 연산 가능

- 임의접근 반복자
  - 배열 기반인 `vector`, `deque` 컨테이너는 임의 접근 반복자 지원
  - `*`,`->`,`++`,`--` 연산 가능
  - 추가로 `[]`, `+=`, `-=`, `+`, `-`, `<`, `>`, `<=`, `>=` 연산 기능 지원
  - 정렬관련 알고리즘은 이 연산이 가능해야 하므로 임의 접근 반복자를 요구함  
