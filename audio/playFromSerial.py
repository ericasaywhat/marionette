import serial
import pygame
pygame.init()




ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
	pygame.mixer.music.load("POESound.wav")
	pygame.mixer.music.play()
	pygame.event.wait()




