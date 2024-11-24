ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=exe
else
	CLEANUP = rm -rf
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean test 
.PHONY: 

PATHU = Unity/src/

ifeq ($(MAKECMDGOALS), libft)
	PATHS = src/libft/
	PATHT = test/libft/
	PATHB = build/libft/
	PATHO = build/libft/objs/
	PATHR = build/libft/results/
endif

ifeq ($(MAKECMDGOALS), get_next_line)
	PATHS = src/get_next_line/
	PATHT = test/get_next_line/
	PATHB = build/get_next_line/
	PATHD = build/get_next_line/depends/
	PATHO = build/get_next_line/objs/
	PATHR = build/get_next_line/results/
endif

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)*.c)
OBJS = $(patsubst $(PATHS)%.c, $(PATHO)%.o, $(wildcard $(PATHS)*.c) ) # ここを修正する

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -DTEST

RESULTS = $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT) )

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`

all:

libft: test
get_next_line: test

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\n\033[31mFAILURES\033[0m:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\n\033[32mPASSED\033[0m:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

# テスト実行します、結果をresultに%.txt形式で出力します。
$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	$(info Run Test $< > Output $@)
	@-./$< > $@ 2>&1

# testオブジェクト、静的ライブラリ、unityオブジェクトをリンクします。
$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)%.a $(PATHO)unity.o
	$(info Link $@)
	$(LINK) -o $@ $^

# testオブジェクトをコンパイルします。
$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

# テストコードをコンパイルします。 TODO: 静的ライブラリを使うものと使わないもので分岐させる
# $(PATHO)%.o:: $(PATHS)%.c
# 	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)libft.a: $(PATHS)libft.a
	cp $< $@

# 静的ライブラリのコンパイル TODO:他のプロジェクトでも対応できる様にする。
$(PATHS)$(MAKECMDGOALS).a:
	$(MAKE) -C $(PATHS) bonus

# unityのコンパイル
$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	$(CLEANUP) build/

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
