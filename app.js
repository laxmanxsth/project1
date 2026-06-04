let tasks = JSON.parse(localStorage.getItem('tasks') || '[]');
const listEl = document.getElementById('list');
const input = document.getElementById('taskInput');

input.addEventListener('keydown', e => {
    if(e.key === 'Enter') addTask();
});

function addTask(){
    const text = input.value.trim();
    if(!text) return;

    const li=document.createElement('li');
    const circle=document.createElement('div');
    circle.style.cssText = 'width:24px; height: 24px; border-radius: 2px solid #444; cursor: pointer; flex-shrink: 0';
    circle.onclick = () => li.classList.toggle('done');

    const span = document.createElement('span');
    span.textContent = text;
    span.style.flex = '1';

    const del = document.createElement('button');
    del.textContent = 'x';
    del.style.cssText = 'background: none; border: none; color: #555; front-size: 20px; cursor: pointer';
    del.onclick = () => li.remove();

    li.append(circle, span, del);
    listEl.appendChild(li);
    tasks.push({ text, done: false });
    localStorage.setItem('tasks', JSON.stringify(tasks));
    input.value= '';
}


function addNote(){
    const grid = document.getElementById('notesGrid');

    const card = document.createElement('div');
    card.style.cssText = 'background: #2b2200; border-raadius: 12px; padding: 14px; margin: 8px 0;';

    const title = document.createElement('input');
    title.placeholder = 'Title';
    title.style.cssText = 'background: none; border: none; color: #e8d87a; font-size: 14px; width: 100%; outline: none;';

    const body = document.createElement('textarea');
    body.placeholder = 'Write your note...';
    body.style.cssText = 'background: none; border: none; color: #e8d87a; font-size: 14px; width: 100%; outline: none; resize: none; min-height: 80px; margin-top: 8px;';

    card.append(title, body);
    grid.appendChild(card);
    body.focus();

}

