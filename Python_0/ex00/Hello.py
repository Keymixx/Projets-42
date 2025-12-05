# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Hello.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carl <carl@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 20:44:23 by carl              #+#    #+#              #
#    Updated: 2025/12/05 01:22:38 by carl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

ft_list[1] = "World!"
ft_tuple = ("Hello", "France!")
ft_set.remove("tutu!")
ft_set.add("Le Havre!")
ft_dict["Hello"] = "42LeHavre"

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)