import requests

r = requests.get("http://dweetr.io/dweet/for/TuNombre?temp=1000")

print (r.url)
