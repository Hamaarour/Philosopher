/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:48:56 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/17 15:12:52 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

int mails = 0;
pthread_mutex_t mutex ;

void *routine()
{
    for (long long i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main ()
{
    pthread_t th[8];

    pthread_mutex_init(&mutex, NULL);
    int i = 0;
    while (i< 8)
    {
        if ( pthread_create(&th[i], NULL, routine, NULL) != 0)
        {
            perror("pthread_create failed");
            return 1;
        }
        i++;
    }
    i = 0;
    while (i < 8)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("pthread_join failed");
            return 1;
        }
        i++;
    }
    
    printf("mails = %d\n", mails);
    pthread_mutex_destroy(&mutex);
    return 0;
        
}