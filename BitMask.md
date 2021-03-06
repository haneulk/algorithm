<기본 지식>
==============
- 컴퓨터는 모든 정수형 변수를 이진수로 표현한다.

- 이때, 이진수 한자리를 bit 라고 표현한다.

- 예를 들어 8비트를 가지고 부호가 없는 정수 0 부터 255 까지를 표현할 수 있다.  
  0 = 00000000  
  255 = 11111111  

- 부호 없는 N 비트 정수형의 경우,  
   2^0 을 최하위 비트(Least significant bit)  
   2^(N-1) 을 최상위 비트(Most significant bit) 라고 부른다.  

- 특정 비트의 값은, 0 또는 1이 될 수 있으며,  
  1인 경우 : "켜져있다"  
  0인 경우 : "꺼져있다" 라고 말한다.  

<비트 연산자>
============
모든 자릿수가 비트 (0 또는 1)로 이루어진 값에 대하여 아래의 연산이 가능하다.

- AND 연산 (기호 : a & b ) : 둘다 1일 경우만 1, 둘중에 하나만 값이 0 이어도 결과는 0 이 된다.  
  ex) 111 & 101 = 101  
  ex) 101 & 100 = 100  
  ex) 001 & 100 = 0  

- OR 연산 (기호 : a | b ) : 둘다 0 일 경우만 0, 둘중에 하나만 값이 1 이면 결과는 1 이 된다.  
  ex) 101 | 100 = 101  
  ex) 011 | 100 = 111  
  ex) 1000 | 0101 = 1101  

- XOR 연산 (기호 : a ^ b ) : 둘이 같은 값 (11 or 00) 이면 0 이 되고, 둘이 다른 값 (10 or 01) 이면 1 이 된다.  
  ex) 101 | 111 = 010  
  ex) 1011 | 0100 = 1111  
  ex) 1011 | 1100 = 0111  

- NOT 연산 (기호 : ~a ) : 두개의 비트 값에 대한 연산이 아닌 단일 비트값에 대하여 적용하는 연산이다. 각 자릿수를 반대값으로 뒤집는다. 즉, 0 인경우 1로 바꾸고, 1 인 경우 0 으로 바꾼다.  
  ex) ~(1011) = 0100  
  ex) ~(0011) = 1100  

- LEFT SHIFT 연산 (기호 : a << b ) : 값 a 의 모든 각 자릿수의 비트를 좌측으로 b 번 만큼 민다. (우측에는 b개의 0 이 붙는다)  
  ex) 1 << 5 = 100000  
  ex) (1 << 5) - 1 = 11111  
  ex) 1011 << 2 = 101100  

- RIGHT SHIFT 연산 (기호 : a >> b ) : 값 a 의 모든 각 자릿수의 비트를 우측으로 b 번 만큼 민다. (좌측에는 b개의 0 이 붙는다)  
  ex) 1101101 >> 2 = 11011  
  ex) 110010  >> 5 = 1  

<비트 가지고 놀기>
=================
위의 내용은 한번쯤 논리학이나 수학을 공부하면서 들어봄직 한 연산일 것이다.  
문제는 이러한 연산법들을 가지고 어떻게 bit를 효과적으로 사용할 수 있을지에 대한 것이다.  

이제부터는 10자리 비트(0 ~9)의 각 자릿수가 피자의 서로다른 토핑의 첨가 유무 생각하고,  
10자리 비트 값으로 피자를 나타낸다고 가정하였을때, 활용가능한 방법들을 알아보자.  

즉, 0100100100 이라는 값은 2^2, 2^5, 2^8 자릿수가 1로 켜짐으로 인해 3개의 토핑이 들어간 피자가 되겠다.  

**1. 공집합과 꽉찬 집합 구하기**  
= 토핑이 아예 없는 피자와, 토핑이 꽉 찬 피자 구하기.  

- 토핑이 없는 피자   
  int emptyPizza = 0  

- 토핑이 꽉찬 피자  
  int fullPizza = (1<< 10) - 1  

**2. 원소 추가**   
= 피자 a 에 n 번 토핑 추가하기 (단, 0 <= n < 10)  

현재 피자에 특정 값만 0 에서 1 로 바꾸고 싶은 경우이다.  
이미 해당 토핑이 들어가 있다면 그냥 1로 유지하면 된다.  

a = a | (1 << n)  

즉, 축약하면  
a  |= (1 << n)  

**3. 원소의 포함여부 확인**  
= 피자 a 에 n 번째 자릿수의 토핑이 들어갔는지 확인하기 (단, 0 <= n < 10)  

페퍼로니의 토핑 자릿수가 n 이라고 합시다.  

if ( a & (1 << n) ) cout << "Pepperoni is included!!!" << endl;  

여기서 빨간부분이 리턴하는 값이 0 또는 (1 << n) 임에 유의 합시다. (참일 경우, true 혹은 1 로 오해하시면 큰일)  

**4. 원소 삭제**  
= 피자 a 에서 n 번째 토핑을 빼려고 합니다. (단, 0 <= n < 10)  

a = a & ~(1 << n)  

축약하면  
a &= ~(1 << n)  

**5. 원소의 토글 (toggle)**  
= 피자 a 의 n 번째 토핑이 없으면 첨가하고, 있으면 제거합니다.  

a = a ^ (1 << n)  

축약하면  
a ^= (1 << n)  

**6. 그 외 집합 연산**  

int added = ( a | b );        // 합집합  
int intersection = ( a & b )  // 교집합  
int removed = ( a & ~b)     // 차집합 a - b  
int toggled = ( a ^ b )       // a 와 b 중 하나에만 들어있는 원소들의 집합 (a 와 b 의 합집합에서 교집합을 뺀 것)  

**7. 최하위 비트 찾아내기**  
= 피자 a 에 올라간 토핑들 중 가장 작은 자릿수의 토핑이 무엇인지 알아내기  

int leastSignificantTopping = a & -a  

ex) 예를들어 5자리 숫자 40 이라고 해보자  
    -40은 2의 보수 연산법 을 사용하여 아래와 같이 (01100) 이 된다.  

    10100 = 40  
    01011 + 1 = 01100 = (-40)  
    10100 & 01100 = 00100 (2^3)  

**8. 최소 비트 지우기**  
= 피자 a 에 올라간 토핑들 중 가장 작은 자릿수의 토핑 빼기  

int removedToppings = a & (a - 1)  

ex)  10110 = a 일때,  
     10110 & (10101) = 10100  
     
     
출처:[Algorithm] 비트마스크(Bit Mask)에 대하여... (비트 연산, 활용법 등)
