# String Container
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
