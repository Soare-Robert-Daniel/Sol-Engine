from selenium import webdriver
from selenium.webdriver.common.keys import Keys

urlSource = open("image.txt","r")
class imageSolwithGoogle:
    urls = []
    def __init__(self):
        for url in urlSource.readlines():
            url = url.strip("\n")
            self.urls.append(url)




    def searchImages(self):
        for url in self.urls:
            self.driver = webdriver.Firefox()

            self.driver.get("https://www.google.com/imghp?sbi=1")

            assert "Google" in self.driver.title

            self.elem = self.driver.find_element_by_name("image_url")
            self.elem.send_keys(url)
            self.elem.send_keys(Keys.RETURN)
            assert "No results found." not in self.driver.page_source

m = imageSolwithGoogle()
m.searchImages()
