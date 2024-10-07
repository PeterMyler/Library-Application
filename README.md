# Library Application

This is my final project for the 2nd-year Software Development module, showcasing an implementation of Object-Oriented Programming (OOP) principles in C++. It demonstrates key concepts such as inheritance, polymorphism, encapsulation, and data abstraction.

## Project Description and Use Cases
  This application is for libraries and librarians to use to keep track of the items they have. It enables a user to create a library, add media items to it (books/magazines) and store the details for the Library in an external file when the application ends. The application can read in data from a text file that the user can also edit. Each library may contain a certain number of items up to a maximum number and items in the library may be sorted, searched, removed, changed, and displayed.

  When a library is created its name must be specified. A value can also be specified to set the maximum allowed items in the library, this limit includes copies of items. If a limit is not specified, the default limit will be 100. Once the limit for the number of items for a library is assigned, it cannot be changed while the application is running.
 
  The items in the library are called media items. These media items may be of type “Book” or “Magazine”. Each item in the library has an associated type, name, and amount (copies). In addition, each Book type item has an associated genre and author, and each Magazine item has an associated company and edition. The author details include their name and country. Magazines do not have authors.

  A public library can setup and use this application to keep track of all the books and magazines they have. The application can store details about the items and how many copies of that item the library has. The librarians can add and remove items when customers take out or bring back the items. They can also sort the items by name, amount, type or even author. They can also help customers search specific items by name to see if the library has them. Since all the information about the items is stored in a singular text file, it can be easily manually modified and read by the application if required.

  Another use-case for this program could be individual people. The software could help them keep track of what books or magazines they own. Items can be searched by name or author, so they can easily tell if they already have a particular book/magazine or not.

## Functional description of the addItem() method
  This function allows for the addition of a specified media item to an existing library provided that the maximum number of items for the Library has not already been reached. 
If the item already exists in the library (e.g. all the details, except for the amount of that item match an already existing item in the library), the amount of the existing item will be increased by the amount of the new item that is being added. If the item is not in the library, it will add it.

Requirement description: Add an item to the library.\
Input: The media item to be added.\
System processing: System checks if the Library has capacity to add the item. If so it then checks if the item is already in the Library.\
Output: If the Library is at its max capacity the system displays an appropriate error message. If the item is already in the library, it will update the increase the current amount of that item by the amount of the new item (by default this value is 1). If the item does not exist then the system will add it to the library.

## Design
![Diagram](https://github.com/PeterMyler/Library-Application/blob/main/Final%20Project%20UML.png?raw=true)

 
## Evaluation
### White box test cases to test the addItem member function outlined below
### Test case 1:
  Add a MediaItem when the max number of items for the Library has not been reached and when the MediaItem is not in the Library.\
Steps:\
1.	Create a Library object and assign a value of 2 for the maximum number of items.
2.	Create two Book objects, each with 1 as the amount.
3.	Call the addItem() function of the Library object to add the two Book objects.
4.	Call the output the getDetails() method of the Library object.

Expected outcome:\
The call to the addItem() method succeeds and the details for the Library object are updated to show that the Library contains the two Book objects.
 

### Test case 2:
Add a MediaItem when the max number of items for the Library has already been reached
Steps:
1.	Create a Library object and assign a value of 2 for the maximum number of items.
2.	Create three Book objects, each with 1 as the amount.
3.	Call the addItem() method of the Library object 3 times to try and add each of the Book objects to the Library object.
4.	Call the output the getDetails() method of the Library object.
 
Expected outcome:\
After the third call to the addItem function the system displays an error message indicating that the Library has reached its capacity. The details of the Library object show that the Library only contains the first two Book objects.
 
### Test case 3:
Add a MediaItem that is already in the Library
Steps:
1.	Create a Library object and assign a value of 10 for the maximum number of items.
2.	Create a Book object, each with 3 as the amount.
3.	Call the addItem function of the Library object twice using the same Book object both times.
4.	Call the output the getDetails() method of the Library object.
 
Expected outcome:\
The first call works and adds the full Book object to the Library. The second call also works but increments the amount of the book already stored in the Library by 3.The details of the Library object show that the Library only contains 1 book, but the amount of that book is 6.

## Conclusions and future work
  The application compiles and works well and fast. It has some inbuilt error detection, but which could be more rigorous and helpful towards the user. The best part about the software is that it can write data stored in it to a .txt file and load that data back in once the program starts again. Although, a better format for this could be a .csv file as it is easier to read and understand as a human. The format for the text file is also very strict and if even one thing is out of place or missing the entire loading process doesn’t work. This could be improved to, for example, allow the details for an object to be in any order, and to display a more accurate error message of where exactly the error occurred if it happened.

Much more functionality could be added to, for example, allow the creation of new object types so the program is not only limited to Books and Magazines.

Overall, while the software could use a lot of work and new features, it is functional and can definitely be used by individual people to keep track of what books and magazines they own.
