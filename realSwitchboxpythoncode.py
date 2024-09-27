import serial
import time


ser = serial.Serial('COM7', 9600)       

print('Enter which switch you would like to turn on and off' )  
#Type A to turn switch one VNA on, type B to turn it off
#Type C to turn switch one Noise on, type D to turn it off
#Type E to turn switch two VNA on, type F to turn it off
#Type G to turn switch two Noise on, type H to turn it off
print('Enter q to quit' )

time.sleep(2)

user_input = 'SwOneVNAon'

while user_input != 'q':
     
     user_input = input("Type input :" )
     byte_command = bytes(user_input, 'utf-8')
     ser.write(byte_command)
     time.sleep(0.5)
     
print('Done')
ser.close
