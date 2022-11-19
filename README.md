# Trabalho-de-ACC
Uma grande instituição educacional expandiu suas unidades acadêmicas e para administrar os
pedidos de serviços internos, necessita de uma solução para o gerenciamento de algumas
informações.
Dos Usuários: Sabe-se, que os usuários do sistema possuem: matrícula, nome completo, nome
da unidade acadêmica, curso vinculado e modalidade de oferta (EAD ou Presencial). O sistema,
objetivando validar qualquer inconsistência recebida, realiza a validação dos dados cadastrados,
visto que todos devem estar preenchidos e uma vez que utiliza a matrícula como chave
identificadora das informações cadastrais de cada usuário.
Dos Serviços: Cada usuário possuirá um arranjo dos seus serviços pedidos no sistema, cujas as
informações armazenadas são: número de identificação (ordem de serviço – OS), descrição do
serviço solicitado (por exemplo: manutenção de ar-condicionado, limpeza, pintura, reposição de
material, entre outros), quantidade e status (cancelado, finalizado, ou em processamento).
Buscando manter a uniformidade do sistema, cada serviço deve possuir uma chave única que o
identifica (OS).
Das Operações: Observando o dia a dia das requisições recebidas, verifica-se que os usuários
realizam poucas mudanças em seu cadastro, contudo é frequente a atualização dos pedidos:
seja na mudança de status, ou na quantidade de um pedido realizado cujo os status está ainda
em aberto (em processamento), ou na inclusão de um novo. No uso da aplicação por
administradores da instituição educacional é permitido a verificação de todo o arranjo de
usuários do sistema e dos pedidos de cada usuário.
Desta forma, no menu principal do sistema é possível:
• Cadastrar um usuário.
• Cadastrar um pedido de serviço, para um usuário já cadastrado.
• Listar todos os usuários, seus dados e o arranjo de seus serviços pedidos.
• Dado um usuário, listar todos os seus serviços pedidos.
• Alterar informações cadastrais de um usuário.
• Alterar informações de um pedido (quantidade e status).
Observe que os usuários estarão organizados em uma estrutura arbórea, e cada usuário possuirá
uma estrutura arbórea para seus pedidos de serviços, contudo, essas estruturas são de
naturezas diferentes dado suas características (inserção e busca). Sabendo de tais características
e necessidades, desenvolva a construção de uma solução com uso adequado das estruturas
arbóreas trabalhadas em sala.
