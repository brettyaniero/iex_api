from bs4 import BeautifulSoup
import time


class Overbought:
    def __init__(self, driver):
        self.url = "https://www.tradingview.com/markets/stocks-usa/market-movers-overbought/"
        self.driver = driver

    def get_data(self):
        overbought_dict = {}

        self.driver.get(self.url)
        time.sleep(1)

        content = self.driver.page_source
        soup = BeautifulSoup(content, features='html.parser')
        for tr in soup.findAll('tr', href=False, attrs={'class': 'tv-data-table__row tv-data-table__stroke tv-screener-table__result-row'}):
            key = ""
            vals = []
            for child in tr.contents:
                if child.text.strip():
                    if not key:
                        # This is unfortunate
                        key = child.contents[0].contents[1].contents[0].text.strip()
                    else:
                        vals.append(child.text.strip())

            overbought_dict[key] = vals

        return overbought_dict
