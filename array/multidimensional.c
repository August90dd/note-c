#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define ARRAY_SIZE(x) (sizeof(x) / (sizeof((x)[0])))

#if ARRAY
// 二维数组形式, 除第一维可以省略size字段, 其他维必须明确指定.
// 数组作为参数时, 长度无法计算, 切记需要传入数组长度参数.
static const char testwords[][16] = { // each word max len == 16
    "I",
    "am",
    "not",
    "a",
    "coder",
};
#else
static const char *testwords[] = {
	"I",
	"am",
	"a",
	"coder",
	NULL // 使用NULL做数组元素个数判断 
};

#endif

#if ARRAY
bool in_it(char const *word, char const (*words)[16], int size)
{
    for (int i = 0; i < size; i++)
		if (strcmp(word, words[i]) == 0)
            return true;
    return false;
}
#else
bool in_it(const char *word, const char **words)
{
    assert(word != NULL);
    while (*words) {
		if (strcmp(word, *words) == 0)
            return true;
        words++;
    }
    return false;
}
#endif

int main(void)
{
	char *word = "not";

#if ARRAY
	if (in_it(word, testwords, ARRAY_SIZE(testwords)))
#else
	if (in_it(word, testwords))
#endif
		printf("Have got the word.\n");
	else
		printf("Have not got the word.\n");
    return 0;
}
