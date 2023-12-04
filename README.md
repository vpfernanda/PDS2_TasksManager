# Task Manager PDS II
O objetivo dessa aplicação é automatizar a criação de rotinas para o usuário, alocando as atividades com horário fixo e livre de acordo com as disponibilidades de horário.
## Como rodar o programa?
Para rodar a aplicação é preciso que primeiramente você tenha o comando "makefile" na sua máquina.
Considerando que você já o tenha, basta digitar no terminal "make main"
Caso você seja um desenvolvedor, você pode executar os testes com o comando "make test"
## Para desenvolvedores
### Organização das pastas
A pasta "include" contém todos os headers.
A pasta "src" contém todos os .cpps
A pasta "test" contém todos os testes.
P.S: Se a criação de outro namespace for necessária crie subpastas com o nome do namespace dentro de include, src e test para manter organizado!
### Namespace
O namespace "task_manager::core" inclui todas as classes essenciais para o funcionamento da aplicação.
## Próximos passos..
Algumas features ficaram pendentes, dentre elas as seguintes:
- Salvar uma rotina no banco de dados e recuperá-la.
- Salvar tarefas no banco de daos e recuperá-las.
- Fazer com que a Agenda salve as tarefas do ano, da mesma maneira que foi implementada os eventos.
## Bibliotecas e programas externos utilizados
### Testes
https://github.com/doctest/doctest
