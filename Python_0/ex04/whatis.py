# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whatis.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carl <carl@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 22:29:15 by carl              #+#    #+#              #
#    Updated: 2025/12/08 00:36:33 by carl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) == 1:
    print()
else:
    try:
        assert len(sys.argv) == 2 
        num = int(sys.argv[1])
    
        if num % 2:
            print ("I'm Odd.")
        else:
            print ("I'm Even.")
    except AssertionError:
        print ("AssertionError: more than one argument is provided")
    except ValueError:
        print ("AssertionError: argument is not an integer")