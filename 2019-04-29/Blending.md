##알파 블렌딩(Alpha Blending)

  투명도 효과를 시물레이션
  일반저긍로 두 장의 이미지 레이어를 앞/뒤로 처리
  알파 블렌딩 수행 결과는 앞면의 배경 픽셀 색상

##함수 설명
 glEnble(GL_BLEND)
    블렌딩 기능을 사용하기 위한 함수 설정

 void glBlendFunc(GLenum sfactor, Glenum dfactor);
    GL_SRC_ALPHA : 먼저 들어온 source
    GL_ONE_MINUS_SRC_ALPHA : 1.0 - 먼저 들어온 source

    그 외에도..
    GL_ZERO, GL_ONE, GL_SRC_COLOR..
