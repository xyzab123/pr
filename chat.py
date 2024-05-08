responses={
    "hi":"how are you?",
    "what is your name?":"i am your chatbot"
}

def chatbot():
    print("i am your chatbot please ask anything\n")

    
    while(True):
        user_input=input("You: ")
        user_input.lower()
        if user_input=="exit":
            print("bye bye")
            break
        response = None
        for key in responses.keys():
            if key in user_input:
                response=responses[key]
                break
        if response:
            print(response)
        else:
            newRes=input("i dont know please teach me the response\n")
            responses[user_input]=newRes;
            print("response added\n")



chatbot()