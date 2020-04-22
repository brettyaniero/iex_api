from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from fundamentals import Fundamentals

# Setup selenium driver
options = Options()
options.headless = True
driver = webdriver.Firefox(options=options)

fdm = Fundamentals("T", driver)
fdm.get_data()

driver.quit()


