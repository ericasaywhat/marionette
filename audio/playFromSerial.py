import serial
import pygame
pygame.init()




ser = serial.Serial('/dev/ttyACM1', 9600)
command = ser.readline()

print command

while command:
	pygame.mixer.music.load("POESound.wav")
	pygame.mixer.music.play()
	pygame.event.wait()
	# pygame.event.get()
	# if event.type =a= KEYDOWN:
 #         if event.key == K_ESCAPE:
 #         	pygame.mixer.stop()
 #         	command = False




