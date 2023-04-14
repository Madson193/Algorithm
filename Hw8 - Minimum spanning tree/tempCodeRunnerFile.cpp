         for (int i = 0; i < temp_size; i++)
                {
                    
                    delete[] graph_temp[i];
                }
                delete[] graph_temp;
                delete[] visited;
                new_stack.clear();