#include "./mlx/mlx.h"
#include <stdio.h>

void	set_param(t_param *param)
{
	param->fd = open 
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_param	param;

	if (argc < 2 || file_name_check(argv[1])) // file_name_check 파일 확장자 확인. 
		return (0);
	set_param(&param); //param 구조체 전체 값 초기화
	get_map(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	mlx_loop(mlx_ptr);
}




// av 로 받은 파일명으로 파일 열기.
// 맵 파싱 1 g 0  등 구성 잘 되어있는지 및 갯수 확인.
// 맵 띄우기
// 키보드 press 입력 받아 wasd esc 구현 및 기능 넣기
//
