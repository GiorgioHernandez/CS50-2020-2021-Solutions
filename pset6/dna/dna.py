import csv
import sys


def main():
    
    #Check correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database.csv sample.txt")

    data = [] #list that will contain the database
    data_filename = sys.argv[1] #csv filename

    with open(data_filename) as database:

        data_reader = csv.DictReader(database) #read the database
        rows = len(data_reader.fieldnames) #quantity of headers 
        headers = data_reader.fieldnames #list of headers

        for person in data_reader:

            for i in range(1, len(headers)):

                person[headers[i]] = int(person[headers[i]]) #convert numeric data to int type

            data.append(person) #add every person to our database

    sequence = [] #list that will contain the DNA sequence to be analized
    sample_filename = sys.argv[2] #txt filename

    with open(sample_filename) as sample:
        sequence = sample.read() #DNA sequence added to our list

    STR = headers[1:rows] #list of headers excluding the names
    MATCH = {} #dictionary that will contain the numbers of the match subject

    for i in range(1,rows):
        MATCH[headers[i]] = 0 #add data to our dictionary and set the initial values to 0

    for i in range(len(STR)):
        count = count_patterns(STR[i],sequence) #analize our data with every pattern
        MATCH[STR[i]] = count #update the repetition count in our dictionary
    
    for person in data:
        
        i = 0
        
        while i < len(STR):       
        
            if person[STR[i]] != MATCH[STR[i]]: #check if a value doesn't match to stop comparing
                break            
            if i == len(STR)-1:  #check if a name has succeded through the matching part
                print(person["name"])
                sys.exit()
            i += 1
            
    print("no match") 


def count_patterns(STR, sequence):

    count = 0
    max_count = 0
    jump = len(STR)
    max_data = len(sequence)
    i = 0

    while i < max_data: # pass through the whole sequence

        sample = sequence[i:i+jump] #analize full patterns

        if sample == STR: #start to count repetitions after a pattern is found

            count += 1
            i += jump-1

            if count > max_count:
                max_count = count

        else:
            count = 0

        i += 1

    return max_count
    

if __name__ == "__main__":
    main()