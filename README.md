
# 📚📖Sistema de Gestão de Bibliotecas

O ojetivo deste projeto é criar um sistema de gestão de uma biblioteca que utilize extensivamente os conceitos de herança e polimorfismo para modelar diversos tipos de livros, leitores e funcionalidades. O sistema permitirá o registo de livros e leitores e respetiva atualização/ manutenção, realizar e gerir empréstimos e controlar outros aspetos como multas e reservas de livros.


## 💫Funcionalidades

- Registo de Livros **(com Hierarquia)**
- Inscrição dos Leitores **(com Hierarquia)**
- Realização de empréstimos **(Polimorfismo)**
- Devolução e controlo de multas
- Sistema de Reservas **(Polimorfismo)**
- Pesquisa e Listagem de Livros **(Herança e Polimorfismo)**
- Relatório de Empréstimos por Tipo de Livros
- Histórico de Empréstimos de Leitores
- Relatório de Multas Pendentes
- Edição de Informações de Leitores
- Edição de Informações de Livros
- Sistema de Notificações de atrasos
- Prorrogação de Empréstimos
- Relatório de Livros por Categoria
- Gravação/ Recuperação de toda a informação referente à Biblioteca
- Interface Gráfica


## ⚙️Requisitos Técnicos

###- **Herança e Polimorfismo:**
    -
    - As classes são projetadas de modo que a herança e o polimorfismo sejam explorados intensivamente. A classe base para os livros será Livro e, a partir dela, serão criadas subclasses como LivroFiccao, LivroCientifico, Revista, etc.
    - A classe Leitor será a classe base para diferentes tipos de leitores, e cada subclasse (como Estudante, Professor, Senior) terá seu próprio comportamento para empréstimos, multas e prorrogações.
###- **Encapsulamento**
    -
    - As classes devem implementar encapsulamento, com os atributos privados e métodos públicos para manipulação de dados.
###- **Classes e Arquitetura**
    -
    - Organizar o código em múltiplos ficheiros, separando as classes em módulos distintos para facilitar a manutenção e expansão do sistema.

## 👨‍💻Autores

- [@xJoelxAlmeidax](https://github.com/xJoelxAlmeidax)
- [@2maas](https://www.github.com/2maas)
- [@renato934](https://www.github.com/renato934)
- Simão Lopes
