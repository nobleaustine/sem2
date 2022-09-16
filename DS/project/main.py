import xml.dom.minidom

def get_rooms():

	doc = xml.dom.minidom.parse("input.svg")
	polygons = doc.getElementsByTagName("polygon")

	result = []

	for polygon in polygons:
		points = polygon.getAttribute("points")
		result.append(list(map(float,points.split(','))))

	return result

rooms = get_rooms()

for room in rooms:
	print(room)