#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *str;
    while(1)
    {
       /* readline함수는 인자($ )를 터미널에 출력하고 라인을 입력 받음*/
        str = readline("$ ");
        if (str)
            printf("%s\n", str);
        else
            break ;
	/* add_history는 커맨드라인의 이전 입력값을 방향키를 통해 확인시킴 */
        add_history(str);
	/* readline은 힙 메모리를 사용하므로 free 시켜줘야 함 */
        free(str);
    }
    return(0);
}
