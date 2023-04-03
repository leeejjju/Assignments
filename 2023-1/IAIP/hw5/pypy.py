from PIL import Image
#import img once
import os

# Open the input image
input_image = Image.open("[image name].jpg")

# Define the size of each subimage
width, height = input_image.size
sub_width = width // 9
sub_height = height // 10

# Create the output directory if it doesn't exist
if not os.path.exists("output"):
    os.makedirs("output")

# Loop through each subimage and save it as a separate file
cnt = 0
for i in range(10):
    for j in range(9):
        # Define the coordinates of the subimage
        left = j * sub_width
        upper = i * sub_height
        right = (j + 1) * sub_width
        lower = (i + 1) * sub_height

        # Crop the subimage
        sub_image = input_image.crop((left, upper, right, lower))

        # Save the subimage as a JPEG file with a formatted name
        filename = f"output/img{cnt}.jpg"
        cnt += 1
        sub_image.save(filename)