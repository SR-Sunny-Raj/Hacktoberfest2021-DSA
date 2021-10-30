# -*- coding: utf-8 -*-

import datetime
import time
    
import requests


def imdb():
    """A program that fetches information related to movies/tv shows from the Internet Movie Database"""
    imdbtoken = "" # You can get this API token from here -> https://www.omdbapi.com/apikey.aspx
    query = str(input("Enter the name of the show or the movie: "))
    if query == "":
        print("\nYou need to enter a search query!")
        time.sleep(10)
        exit()

    start = datetime.datetime.now()
    print("\nConnecting...\n")
    query = query.replace(" ","+")
    api = f"https://www.omdbapi.com/?t={query}&plot=full&apikey={imdbtoken}"

    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) '
                             'Chrome/41.0.2228.0 Safari/537.36'}

    r = requests.get(api, headers=headers)
    if r.status_code != 200:
        print("Connection Failed D:")
        time.sleep(3)
        exit()
    
    print("Connected!\n\n")

    result = r.json()
    for key, value in result.items():
        if type(value) is not list:
            print (key, value, sep=" - ")
        else:
            pass 
    
    end = datetime.datetime.now()
    total_time = (end - start).total_seconds()
    print(f"\nDone!")

    input(f"Total time taken : {total_time} seconds")

if __name__ == '__main__':
    imdb()
