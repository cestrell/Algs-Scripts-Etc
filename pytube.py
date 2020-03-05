import webbrowser
import sys

url = sys.argv[1]
download = url[:url.find(".") + 1] + "ss" + url[url.find(".") + 1:]

webbrowser.open(download)
