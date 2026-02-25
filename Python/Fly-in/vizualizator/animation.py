# import pygame
# import sys
# # sys.path.append('.')
# # from parsing import parser


# display_width = 800
# display_height = 600
# radius = 30


# def run():
#     info = parser("maps/challenger/01_the_impossible_dream.txt")

#     pygame.init()

#     screen = pygame.display.set_mode((display_width, display_height))
#     clock = pygame.time.Clock()

#     screen.fill((0, 0, 0))

#     for zone in info["zones"]:
#         print((zone.x, zone.y))
#         pygame.draw.circle(screen, (255, 255, 0), (zone.x, zone.y), radius)

#     pygame.display.update()
#     running = True

#     while running:
#         for event in pygame.event.get():
#             if event.type == pygame.QUIT:
#                 running = False
#         clock.tick(60)

#     pygame.quit()


# run()
