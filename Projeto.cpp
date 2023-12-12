#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Contato
{
private:
    string nome;
    string numero;

public:
    Contato(string id, string celular)
    {
        nome = id;
        numero = celular;
    }
    ~Contato() {}
    string getNome()
    {
        return nome;
    }
    string getNumero()
    {
        return numero;
    }
    void setNome(string id)
    {
        nome = id;
    }
    void setNumero(string celular)
    {
        numero = celular;
    }
};

class ListaContatos
{
private:
    vector<Contato *> contatos;

public:
    ~ListaContatos()
    {
        excluirContatos();
    }
    void adicionarContato(string id, string celular)
    {
        Contato *novoContato = new Contato(id, celular);
        contatos.push_back(novoContato);
    }
    void excluirContatos()
    {
        for (auto &contato : contatos)
        {
            delete contato;
        }
    }
    void exibirContatos()
    {
        if (contatos.empty())
        {
            cout << "Nenhum contato ainda :(" << endl;
        }
        else
        {
            for (const auto &contato : contatos)
            {
                cout << "Nome: " << contato->getNome() << ", Telefone: " << contato->getNumero() << endl;
            }
        }
    }
    void exportarArquivo(string nomeArq)
    {
        nomeArq.append(".txt");
        ofstream arquivo(nomeArq);
        for (const auto &contato : contatos)
        {
            arquivo << contato->getNome() <<" "<< contato->getNumero() << endl;
        }
        arquivo.close();
    }
    void importarArquivo(string nomeArq)
    {
        ifstream arquivo(nomeArq);
        string nome, celular;

        while (arquivo >> nome >> celular)
        {
            adicionarContato(nome, celular);
        }
        arquivo.close();
    }
};

int main()
{
    ListaContatos lista;
    int controle = 1;
    while (controle)
    {
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Criar novo contato" << endl;
        cout << "2. Listar contatos" << endl;
        cout << "3. Importar contatos" << endl;
        cout << "4. Exportar contatos" << endl;
        cout << "5. Apagar contatos" << endl;
        cout << "0. Sair" << endl
             << endl;

        cin >> controle;

        cout << endl;

        switch (controle)
        {
        case 1:
        {
            string nome, numero;
            cout << "Digite o nome do contato: ";
            cin >> nome;
            cout << "Digite o numero do contato: ";
            cin >> numero;
            cout << endl;
            lista.adicionarContato(nome, numero);
            break;
        }
        case 2:
            lista.exibirContatos();
            cout << endl;
            break;
        case 3:
        {
            string nomeArq;
            cout << "Digite o nome do arquivo de importacao: ";
            cin >> nomeArq;
            lista.importarArquivo(nomeArq);
            cout << endl;
            break;
        }
        case 4:
        {
            string nomeArq;
            cout << "Digite o nome do arquivo de exportacao: ";
            cin >> nomeArq;
            lista.exportarArquivo(nomeArq);
            cout << endl;
            break;
        }
        case 5:
            lista.excluirContatos();
            cout << "Contatos excluidos com sucesso!" << endl;
            cout << endl;
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Selecione uma das opções listadas acima." << endl;
            cout << endl;
        }
    }
    return 0;
}