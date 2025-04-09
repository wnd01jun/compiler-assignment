# 컴파일러와 명령어
LEX = flex
YACC = yacc
CC = gcc

# 파일명 설정
LEX_SRC = lee.l
YACC_SRC = lee.y
MAIN_SRC = main.c
OUTPUT = parser

# 자동 생성 파일
LEX_GEN = lex.yy.c
YACC_GEN_C = y.tab.c
YACC_GEN_H = y.tab.h

# 기본 규칙
all: $(OUTPUT)

# 실행 파일 만들기
$(OUTPUT): $(YACC_GEN_C) $(LEX_GEN) $(MAIN_SRC)
	$(CC) -o $(OUTPUT) $(YACC_GEN_C) $(LEX_GEN) $(MAIN_SRC) -lfl

# yacc 파일 처리
$(YACC_GEN_C) $(YACC_GEN_H): $(YACC_SRC)
	$(YACC) -d $(YACC_SRC)

# lex 파일 처리
$(LEX_GEN): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

# 깨끗하게 삭제
clean:
	rm -f $(OUTPUT) $(LEX_GEN) $(YACC_GEN_C) $(YACC_GEN_H)

.PHONY: all clean
