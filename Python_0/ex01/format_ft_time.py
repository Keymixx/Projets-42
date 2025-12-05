# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    format_ft_time.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carl <carl@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 01:23:18 by carl              #+#    #+#              #
#    Updated: 2025/12/05 01:59:38 by carl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time

time_unix = time.time()
scien_not = "{:.2e}".format(time_unix)
date = time.ctime(time_unix)
tab = date.split()

print(f"Seconds since January 1, 1970: {time_unix:,.4f}", end=" ")
print(f"or {scien_not} in scientific notation")
print(tab[1], tab[2], tab[4])