class publisher:
    def __init__(self,name):
        self.name = name

    def display(self):
        print(f"publisher:{self.name}")

class book(publisher):
    def __init__(self,name,title,author):
        super().__init__(name)
        self.author=author
        self.title=title  
         
    def display(self):
        print(f"{self.title}, written by {self.author}")
        super().display()

class Python(book):
    def __init__(self,name,title,author,price,no_of_pages):
        super().__init__(name,title,author)
        self.price=price
        self.no_of_pages=no_of_pages

    def display(self):
        super().display()
        print(f"price:${self.price}\n{self.no_of_pages} pages")

book=Python(name="some",title="sdffs",author="ali",price="15",no_of_pages=12)
book.display()    
