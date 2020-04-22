from bs4 import BeautifulSoup
import time


class Fundamentals:
    def __init__(self, symbol, driver):
        self.symbol = symbol
        self.url = self.build_url()
        self.driver = driver

    def build_url(self):
        return "https://www.tradingview.com/symbols/" + self.symbol + "/"

    def get_data(self):
        fundamentals_dict = {}
        self.driver.get(self.url)
        time.sleep(1)

        content = self.driver.page_source
        soup = BeautifulSoup(content, features='html.parser')
        for div in soup.findAll('div', href=False, attrs={'class': 'tv-widget-fundamentals__row'}):
            key = ""
            val = ""
            for child in div.children:
                if child.string.strip():
                    if not key:
                        key = child.string.strip()
                    else:
                        val = child.string.strip()

            fundamentals_dict[key] = val

        for item in fundamentals_dict:
            print(item + ": " + fundamentals_dict[item])

        return fundamentals_dict

