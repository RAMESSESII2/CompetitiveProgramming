u
import time

chromedriver = "C:\\Users\\Hp\\Downloads\\chromedriver.exe"
driver = webdriver.Chrome(chromedriver)
driver.get("https://web.whatsapp.com/")
time.sleep(20)

# name=str(input('Enter the name of user or group: '))
# msg=input('Enter your message: ')
# count=int(input("How many times: "))
name = "Mommi"

print("QR code scanned.")
user = findElement(By.xpath("//span[@title={}]".format(name)))
# user= driver.find_element_by_xpath('//span[@title={}]'.format(name))
user.click()
# msgbox=driver.find_element_by_class_name('_2S1VP copyable-text selectable-text')
# for i in range(count):
# 	msgbox.send_keys(msg)
# 	button=diver.find_element_by_class_name('_35EW6')
# 	button.click()