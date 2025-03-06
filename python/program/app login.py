class App:
    def __init__(self):
        self.peopleArray = []

    def register(self, email, password, name):
        print("Register")

    def login(self, email, password):
        for person in self.peopleArray:
            if person[0] == email:
                if person[1] == password:
                    print("successfully login")
                else:
                    print("not logged in")
            else:
                print("not exist")
        print("login")


app = App()
email: str = "a123"
password: int = 1234
name: str = "tomy"
app.register(email, password, name)
app.login(email, password)
