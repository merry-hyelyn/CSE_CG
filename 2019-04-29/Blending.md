## 알파 블렌딩(Alpha Blending)

  -투명도 효과를 시물레이션<br>
  -일반적으로 두 장의 이미지 레이어를 앞/뒤로 처리<br>
  -알파 블렌딩 수행 결과는 앞면의 배경 픽셀 색상<br>

## 함수 설명
 -glEnble(GL_BLEND)<br>
    블렌딩 기능을 사용하기 위한 함수 설정<br><br>

 -void glBlendFunc(GLenum sfactor, Glenum dfactor);<br>
    GL_SRC_ALPHA : 먼저 들어온 source<br>
    GL_ONE_MINUS_SRC_ALPHA : 1.0 - 먼저 들어온 source<br>

    그 외에도..
    GL_ZERO, GL_ONE, GL_SRC_COLOR..
