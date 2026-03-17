#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
int main()
{
    printf("%ld\n", get_current_time());
    ft_usleep(500);
    printf("%ld\n", get_current_time());
    return(0);
}