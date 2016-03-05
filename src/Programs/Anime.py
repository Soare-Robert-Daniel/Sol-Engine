import urllib3
import sys
import certifi
import time
import webbrowser

# Cerere & Setari
http = urllib3.PoolManager(
    cert_reqs='CERT_REQUIRED', # Force certificate check.
    ca_certs=certifi.where(),  # Path to the Certifi bundle.
)
url = "http://animeshow.tv/"
new = 2

# You're ready to make verified HTTPS requests.
# try:
#     r = http.request('GET', url)
# except urllib3.exceptions.SSLError as e:
#     print ("Error")


# Fisier
try:
    infoText = open("text.txt","w")
    infoAnime = open("anime.txt","r")
    infoSettings = open("settings.txt","r")
except:
    print("text.txt , anime.txt , settings.txt must be in the same fille with the application !")

# Variabile
# anime = {
#     "Rakudai": 0 ,
#     "Asterisk": 0 ,
#     "Lucifer": 0
# }


animeList = {}
for a in infoAnime.readlines():
     a = a.strip('\n')
     animeList[a] = 0;

animeSettings = {}
try:
    for set in infoSettings.readlines():
        set = set.split()
        if(set[0] == "Time"):
            animeSettings["Time"] = float(set[1].strip("\n"))
        elif(set[0] == "OpenSite"):
            animeSettings["OpenSite"] = set[1].strip("\n")
        elif(set[0] == "OpenSiteCount" and (animeSettings["OpenSite"] == "true")):
            animeSettings["OpenSiteCount"] = int(set[1].strip("\n"))
        elif(set[0] == "OpenSiteCount" and (animeSettings["OpenSite"] == "false")):
            animeSettings["OpenSiteCount"] = 0
except:
    print("Error at reading file settings.txt !!!")
#textSite = str(r.read())

# text = text.split("<table id=\"tbl-latest-episodes\">")
# text1 = text[1].split("<div id=\"new-series\">")
# text2 = text1[0].split("day ago")
# infoText.write(text2[0])

def getSite(text):
    text = text.split("<table id=\"tbl-latest-episodes\">")
    text = text[1].split("<div id=\"new-series\">")
    text = text[0].split("day")
    print("Analyze...")
    infoText.write(text[0])
    return text[0]

def loop(timeApp):

    stop = 0
    countOpenSite = 0
    while(not stop):
        print( "Time: " + time.asctime( time.localtime(time.time()) ))
        try:
            r = http.request('GET', url)
            print("Scan...")
        except urllib3.exceptions.SSLError as e:
            print ("Error")

        textSite = str(r.read())
        textSite = getSite(textSite)

        found = 0

        for anime in animeList.keys():
            if ( textSite.find(anime) != -1 and animeList[anime] == 0):
                print( anime + " found :)")
                animeList[anime] = 1
                found = 1

        if(found == 1):
            countOpenSite = countOpenSite + 1
            if(countOpenSite <= animeSettings["OpenSiteCount"]):
                webbrowser.open( url , new = new)
        else:
            print("Sol has not found any anime! :(")
        print( "+------------------------------+" )

        time.sleep(timeApp * 60)

loop(animeSettings["Time"])

x = input("Press any key to continue...")
