# import module
import pandas as pd
import requests
from bs4 import BeautifulSoup

# since some of the websites block web scarping
# it tels the amazon application that chrome version 107 on macos
# trying to access the web app, then it sends request
HEADERS = ({'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 13_0_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36'})

# user define function
# Scrape the data
def getdata(url):
	r = requests.get(url, headers=HEADERS)
	return r.text


def html_code(url):

	# pass the url
	# into getdata function
	htmldata = getdata(url)
	soup = BeautifulSoup(htmldata, 'html.parser')

	# display html code
	return (soup)


url = "https://www.amazon.in/Computer-Networks-5e-5th-Tanenbaum/dp/9332518742/?_encoding=UTF8&pd_rd_w=CPNJu&content-id=amzn1.sym.e932aeaf-89ea-47b8-9c31-e92696d33d85&pf_rd_p=e932aeaf-89ea-47b8-9c31-e92696d33d85&pf_rd_r=FDR7V15P70JRRN0NDB6Q&pd_rd_wg=QgwCr&pd_rd_r=9c147adf-e1a9-4e09-ba28-5d3389da9135&ref_=pd_gw_ci_mcx_mr_hp_d"

soup = html_code(url)
# print(soup)


def cus_data(soup):
	# find the Html tag
	# with find()
	# and convert into string
	data_str = ""
	cus_list = []

	for item in soup.find_all("span", class_="a-profile-name"):
		data_str = data_str + item.get_text()
		cus_list.append(data_str)
		data_str = ""
	return cus_list


cus_res_ = cus_data(soup)
cus_res = []
for i in cus_res_:
    if 'Amazon' not in i:
        cus_res.append(i)
print(cus_res)


def cus_rev(soup):
	# find the Html tag
	# with find()
	# and convert into string
	data_str = ""

	for item in soup.find_all("div", class_="a-expander-content reviewText review-text-content a-expander-partial-collapse-content"):
		data_str = data_str + item.get_text()

	result = data_str.split("\n")
	return (result)


rev_data = cus_rev(soup)
rev_result = []
for i in rev_data:
	if i == '':
		pass
	else:
		rev_result.append(i)
print(rev_result)

# initialise data of lists.

data = {'Name': cus_res,
        'review': rev_result}

# Create DataFrame
df = pd.DataFrame(data)

# Save the output.
df.to_csv('amazon_review.csv')