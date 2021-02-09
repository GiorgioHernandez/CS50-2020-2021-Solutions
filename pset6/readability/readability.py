from cs50 import get_string
import re


text = get_string("Text: ")

# count the number of words in the text
words = len(re.findall(r"[ ]+", text))  # the 1st argument makes that every space founded mark the end of a word
words += 1

# count the number of letters in the text
letters = len(re.findall(r'\w', text))  # here is going to count every character that is used to make words

# count the number of sentences in the text
sentences = len(re.findall('[.!?]', text))  # the characters . ! ? are used to show the end of a sentence

L = (letters/words)*100
S = (sentences/words)*100

Index = 0.0588 * L - 0.296 * S - 15.8

if Index >= 16:
    print("Grade 16+")
elif Index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(Index)}")