!/usr/bin/env python3

import csv

# open the file in universal line ending mode
with open('./csv/global_1751_2014.csv', 'rU') as infile:
	# read the file as a dictionary for each row ({header : value})
	reader = csv.DictReader(infile)
	data = {}
	# fill the data dictionary of values
	for row in reader:
		for header, value in row.items():
			try:
				#print( type(value) ) # value is of type string
				data[header].append( value )
			except KeyError:
				data[header] = [ value ]

# now we have a single dictionary composed with as many keys as many headers in the csv
# for each key we have an associated list which is made of all elements of that particular
# column.

# get all the keys from the CSV
keys = list( data.keys() )

"""
# Uncomment the lines below if you want less data
# The snipped below is responsible to reduce the number of data
# for each list.
for key in keys:
	# for each key inside the data dictionary, remove some data from the
	# corresponding list according to the index of the element
	shorterList = [data[key][k] for k in range(len(data[key])) if k%10 < 1]
	data[key] = shorterList
"""

"""
# print a txt files with all the associations
# after we have created all the text files to be copied inside an Arduino header files
# we can print to console all the correspondences between the year column and the associated values

file = open("./txts/all_associations.txt", "w")

for i in range( len(keys) ):
	separator = "\n\n***************************\nkey[{}] - {}\n***************************\n\n".format(i, keys[i])
	#print( "\n***************************\nkey[", i, "] ", keys[i],"\n***************************" )
	file.write( separator )
	for i, v in enumerate( data[ keys[i] ] ):
		string = "{}) {} - {}\n".format(i, data[ keys[0] ][i], v)
		#print(i, ") ", data[ keys[0] ][i], " - ", v)
		print( string )
		file.write( string )
"""

# get the number of records inside the dataset
numbersOfRecords = len(data[ keys[0]] )
print( "CSV file contains a total of {} recods per column".format(numbersOfRecords ))


# Create the .txt files:
# These fils will contains data expressed in a format easy to be copied and pasted
# inside an Arduino header file.
# Only addition to make the Arduino side, is the data type, array name, and
# to initialize a constant which will save the number of records inside these arrays
chars_to_remove = ["[", "]", "'"]

"""
for i in range(len(keys)):
	fileName = keys[i]
	file = open("./txts/column_{0}.txt".format( fileName ), "w")
	file.write( "= {")

	# now replace single quote with double quotes and square brakets with curly ones
	# but first of all let's convert the string list into an int one.
	dataString = ''.join([c for c in str( data[ keys[i]] ) if c not in chars_to_remove])
	file.write( dataString )
	file.write("};" )
"""

for k in keys:
	file = open("./txts/column_{0}.txt".format( k ), "w")
	file.write( "= {")
	# now replace single quote with double quotes and square brakets with curly ones
	# but first of all let's convert the string list into an int one.
	dataString = ''.join([c for c in str( data[k] ) if c not in chars_to_remove])
	file.write( dataString )
	file.write("};" )

	# now convert list of string into list of integers
	# (no method to convert float values for the moment :( )
	# and then check for the minimum and maximum value.
	# Print these values inside the txt file too.
	convertedData = []
	try:
		convertedData = [int( d ) for d in data[ k ] ]
		maximum = max(convertedData)
		minimum = min(convertedData)
		file.write( "\nint DATAMIN = {};\nDATAMAX = {};".format(minimum, maximum) )
	except:
		print("I was not able to convert")
