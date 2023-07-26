A C program that defines  an enumeration type called 'Color' with values RED, GREEN, BLUE, YELLOW,  and  ORANGE. 
Create  a  function  called  'colorMixer'  thattakes  two  'Color'  enumeration values and a function pointer as arguments.
The function pointer should point to a function that takes two 'Color' enumeration values and returns a new 'Color' enumeration value as a result of mixing the input colors.
Mixing two colors is done in the following way:
•First, each color is represented by a length-3 vector.
RED is [1, 0, 0]
GREEN is [0, 1, 0]
BLUE is [0, 0, 1]
YELLOW is [0.5, 0.5, 0]
ORANGE is [0.5, 0.4, 0.2]
•When the colors to be mixed has the followinglength-3 vectors [x1,x2,x3] and [y1,y2,y3], the mixed color is [(x1+y1)/2, (x2+y2)/2, (x3+yr)/2] and the corresponding enumerated color is the closest to this one using Euclidean distance.
