#include <iostream>
#include <vector>

#include <getopt.h>

std::vector<std::string>* handledOptions = new std::vector<std::string>();

void handleHelp()
{
    std::cout << "Використана опція --help(-h);" << std::endl;
}


void handleVersion()
{
    std::cout << "Використана опція --version (-v);" << std::endl;
}


void handleCreate(char* arg)
{
    std::cout << "Використана опція --create(-i) з параметром: " << arg << std::endl;
}


void handleSum(char* arg)
{
    if (arg == nullptr)
    {
        std::cout << "Використана опція --sum(-s);" << std::endl;
    }
    else
    {
        std::cout << "Використана опція --sum(-s) з параметром: " << arg << std::endl;
    }
}


void handleCount()
{
    std::cout << "Використана опція --count(-c)" << std::endl;
}


void handleReverse()
{
    std::cout << "Використана опція --reverse(-r)" << std::endl;
}


bool isAlreadyHandled(const std::string& optionName)
{
    for (auto& argument : *handledOptions)
    {
        if (optionName == argument)
        {
            return true;
        }
    }
    return false;
}


bool isOnlyOne(int optionsCount, const std::string& optionName)
{
    if (optionsCount != 2)
    {
        std::cout << "Опція --" << optionName << " має бути єдиною у списку параметрів." << std::endl;
        return false;
    }
    return true;
}


int main(int argc, char* const* argv)
{
    int current_option;

    const char* short_options = "hvcri:s::";

    struct option long_options[] = {
            {"help",    no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'v'},
            {"count",   no_argument, nullptr, 'c'},
            {"reverse", no_argument, nullptr, 'r'},
            {"create",  required_argument, nullptr, 'i'},
            {"sum",     optional_argument, nullptr, 's'},
            {nullptr, 0, nullptr, 0}
        };

    int option_index = 0;


    while ((current_option = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        std::string option_name;

        for (struct option& element : long_options)
        {
            if (element.val == current_option)
            {
                option_name = element.name;
                break;
            }
        }

        if (!(option_name.empty()) && isAlreadyHandled(option_name))
        {
            continue;
        }

        handledOptions -> push_back(option_name);


        switch (current_option)
        {
        case 'h':
            if (isOnlyOne(argc, option_name))
            {
                handleHelp();
            }
            break;

        case 'v':
            if (isOnlyOne(argc, option_name))
            {
                handleVersion();
            }
            break;

        case 'c':
            handleCount();
            break;

        case 'r':
            handleReverse();
            break;

        case 'i':
            handleCreate(optarg);
            break;

        case 's':
            handleSum(optarg);
            break;

        case '?':
            break;

        default:
            abort();
        }
    }

    if (optind < argc)
    {
        std::cout << "Значення аргументів без параметрів: " << std::endl;

        while (optind < argc)
        {
            std::cout << argv[optind++] << std::endl;
        }
    }

    else
    {
        std::cout << "Не було введено жодних значень аргументів без параметрів." << std::endl;
    }

    return 0;
}