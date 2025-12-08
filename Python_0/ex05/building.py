# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    building.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carl <carl@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 02:03:33 by carl              #+#    #+#              #
#    Updated: 2025/12/08 02:45:44 by carl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def main():
    dig = 0
    upp = 0
    low = 0
    space = 0
    pun = 0
    char = 0
    for c in sys.argv[1]:
        print(c)
        if c.isdigit():
            dig += 1
        elif c.isupper():
            upp += 1
        elif c.islower():
            low += 1
        elif c == " ":
            space += 1
        elif not c.isalnum and not c == " ":
            pun += 1
        char += 1
    print(f"Nombre = {dig}")
    print(f"Maj = {upp}")
    print(f"Min = {low}")
    print(f"Space = {space}")
    print(f"Ponc = {pun}")
    print(f"Char tot = {char}")



if __name__ == "__main__":
    main()