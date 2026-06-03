import os

FILE = "tasks.txt"

def load_tasks():
    if os.path.exists(FILE):
        with open(FILE, "r") as f:
            return [line.strip() for line in f.readlines()]
    return []

def save_tasks(todos):
    with open(FILE, "w") as f:
        for task in todos:
            f.write(task + "\n")

todos = load_tasks()

while True:
    print("\n1. Add task")
    print("2. View tasks")
    print("3. Delete task")
    print("4. Quit")

    choice = input("Choose: ")

    if choice == "1":
        task = input("Enter task: ")
        todos.append(task)
        save_tasks(todos)
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
            save_tasks(todos)
            print("Deleted!")
        else:
            print("Task not found!")

    elif choice == "4":
        break

