todos = []

while True:
    print("\n1. Add task")
    print("2. View tasks")
    print("3. Delete task")
    print("4. Quit")
    
    choice = input("Choose: ")
    
    if choice == "1":
        task = input("Enter task: ")
        todos.append(task)
        print("Task added!")
    
    elif choice == "2":
        if len(todos) == 0:
            print("No tasks!")
        else:
            for i, task in enumerate(todos, 1):
                print(f"{i}. {task}")
    
    elif choice == "3":
        task = input("Enter task to delete: ")
        if task in todos:
            todos.remove(task)
            print("Deleted!")
        else:
            print("Task not found!")
    
    elif choice == "4":
        break

